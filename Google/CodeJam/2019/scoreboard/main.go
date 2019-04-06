package main

import "fmt"

func main() {
	// test := "Pożeracz_pączków_z_lukrem"
	// lol := encodeToBase64([]byte(test))
	// fmt.Println(lol)
	// fmt.Println(decodeFromBase64([]byte(lol)))

	config := parseConfigFile()
	api := apiData{contestID: config.ContestID}

	// getHandleResults(&api, config.Handles)
	contestants := api.getAllResults()
	for _, contestant := range contestants {
		// fmt.Printf("%6f %30s %30s\n", contestant.rank, contestant.handle, contestant.score1)
		if contestant.country == "Taiwan" {
			fmt.Printf("%6.0f %30s %6.0f\n", contestant.rank, contestant.handle, contestant.score1)
		}
	}
}

func getHandleResults(api *apiData, handles []string) {
	for _, handle := range handles {
		api.getResultByHandle(handle)
	}
}
