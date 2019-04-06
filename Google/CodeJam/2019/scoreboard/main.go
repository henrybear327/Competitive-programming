package main

import "fmt"

func main() {
	config := parseConfigFile()
	api := apiData{contestID: config.ContestID}

	// getHandleResults(&api, config.Handles)
	contestants := api.getAllResults()
	for _, contestant := range contestants {
		fmt.Println(contestant.handle, contestant.rank, contestant.score1)
		if contestant.country == "Taiwan" {
			fmt.Println(contestant.handle, contestant.rank, contestant.score1)
		}
	}
}

func getHandleResults(api *apiData, handles []string) {
	for _, handle := range handles {
		api.getResultByHandle(handle)
	}
}
