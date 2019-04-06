package main

func main() {
	config := parseConfigFile()
	api := apiData{contestID: config.ContestID}

	getHandleResults(&api, config.Handles)
}

func getHandleResults(api *apiData, handles []string) {
	for _, handle := range handles {
		api.getResultByHandle(handle)
	}
}
