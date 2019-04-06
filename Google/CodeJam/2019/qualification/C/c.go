package main

import (
	"fmt"
	"math/big"
	"sort"
)

func gcd(a, b *big.Int) *big.Int {
	if b.Cmp(big.NewInt(0)) == 0 {
		return a
	}
	return gcd(b, a.Mod(a, b))
}

type bigIntArray []*big.Int

func (s bigIntArray) Len() int {
	return len(s)
}

func (s bigIntArray) Swap(i, j int) {
	s[i], s[j] = s[j], s[i]
}

func (s bigIntArray) Less(i, j int) bool {
	return s[i].Cmp(s[j]) <= 0 // x < y
}

func solve() string {
	ans := ""

	n := new(big.Int)
	fmt.Scanf("%s", n)
	l := 0
	fmt.Scanf("%d", &l)

	inp := make([]*big.Int, l)
	for i := 0; i < l; i++ {
		inp[i] = new(big.Int)
		fmt.Scanf("%d", inp[i])
		// log.Println("inp", i, inp[i])
	}

	res := make([]*big.Int, l+1)
	for i := 0; i < l+1; i++ {
		res[i] = new(big.Int)
	}

	idx := -1
	for i := 1; i < l; i++ {
		if inp[i].Cmp(inp[i-1]) == 0 { // AAA or ABA
			continue
		}

		a := new(big.Int)
		a.SetString(inp[i-1].String(), 10)
		b := new(big.Int)
		b.SetString(inp[i].String(), 10)
		g := gcd(a, b)
		idx = i
		res[i] = g
		break
	}
	// if idx == -1 {
	// 	log.Fatalln("Fucked")
	// }
	// log.Println(idx, res[idx])

	s := make(map[string]bool)
	for i := idx - 1; i >= 0; i-- {
		// log.Println(inp[i], res[i+1])
		res[i].Div(inp[i], res[i+1])
		// log.Println(i, res[i])
	}
	for i := idx + 1; i < l+1; i++ {
		res[i].Div(inp[i-1], res[i-1])
	}
	for i := 0; i < l+1; i++ {
		s[res[i].String()] = true
	}

	primeString := make(bigIntArray, 0)
	for key := range s {
		tmp := new(big.Int)
		fmt.Sscanf(key, "%s", tmp)
		primeString = append(primeString, tmp)
	}
	sort.Sort(primeString)

	prime := make(map[string]string)
	for i, str := range primeString {
		prime[str.String()] = string(i + 'A')
	}

	for i := 0; i < l+1; i++ {
		ans += prime[res[i].String()]
	}

	return ans
}

func main() {
	ncase := 0
	fmt.Scanf("%d", &ncase)
	for i := 1; i <= ncase; i++ {
		res := solve()
		fmt.Printf("Case #%d: %s\n", i, res)
	}
}
