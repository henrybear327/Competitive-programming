package main

// Thanks Andy Chen for helping me with debugging

import (
	"fmt"
	"log"
	"os"
	"runtime"
	"strconv"
	"sync"
)

// NumOfPrime is the max number of prime to be generated
const NumOfPrime int = 100000000

// NumOfWorker is the max number of go routines to be created
const NumOfWorker int = 4

type Answer struct {
	sync.Mutex
	primeCount   int
	largestPrime int64
}

func genPrime() []int {
	primeTable := make([]bool, NumOfPrime)
	result := make([]int, 0)
	for i := 0; i < NumOfPrime; i++ {
		primeTable[i] = true
	}

	primeTable[0] = false
	primeTable[1] = false
	for i := 2; i < NumOfPrime; i++ {
		if primeTable[i] {
			result = append(result, i)
			for j := i * i; j < NumOfPrime; j += i {
				primeTable[j] = false
			}
		}
	}

	return result
}

func isPrime(candidate int64, primeList []int) bool {
	// fmt.Println("candidate", candidate)
	if candidate > int64(NumOfPrime)*int64(NumOfPrime) {
		log.Fatal("Out of range")
	}

	for i := 0; i < len(primeList); i++ {
		if int64(primeList[i])*int64(primeList[i]) > candidate {
			break
		}

		if candidate%int64(primeList[i]) == 0 {
			return false
		}
	}

	return true
}

func worker(workerID int, job <-chan int64, done chan<- bool, answer *Answer, primeList []int) {
	// lock thread (1 to 1 relation)
	runtime.LockOSThread()
	defer func() {
		runtime.UnlockOSThread()
	}()

	fmt.Println(workerID, "starts")

	localAnswer := Answer{primeCount: 0, largestPrime: -1}

	for {
		candidate, hasMore := <-job
		if hasMore {
			ret := isPrime(candidate, primeList)
			if ret {
				// fmt.Println("prime", i)
				localAnswer.primeCount++
				if candidate > localAnswer.largestPrime {
					localAnswer.largestPrime = candidate
				}
			}
		} else {
			break
		}
	}

	answer.Lock()
	answer.primeCount += localAnswer.primeCount
	if localAnswer.largestPrime > answer.largestPrime {
		answer.largestPrime = localAnswer.largestPrime
	}
	answer.Unlock()

	fmt.Println(workerID, "ends")

	done <- true
}

func main() {
	// set cpu
	log.Println("CPU cores", runtime.NumCPU())
	runtime.GOMAXPROCS(runtime.NumCPU())

	// parse flag
	target, err := strconv.ParseInt(os.Args[1], 10, 64)
	if err != nil {
		log.Fatalln(err)
	}

	primeList := genPrime()

	data := Answer{primeCount: len(primeList), largestPrime: int64(primeList[len(primeList)-1])}

	// setup workers
	candidate := make(chan int64, 10000)
	done := make(chan bool)
	for w := 1; w <= NumOfWorker; w++ {
		go worker(w, candidate, done, &data, primeList)
	}

	for i := int64(NumOfPrime); i <= target; i++ {
		if i%2 == 0 {
			continue
		}

		candidate <- i

	}

	// close workers
	close(candidate)

	// wait for all workers to finish syncing
	for i := 0; i < NumOfWorker; i++ {
		<-done
	}

	// print answer
	fmt.Println(data.largestPrime, data.primeCount)
}
