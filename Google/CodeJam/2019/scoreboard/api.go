package main

import (
	"encoding/json"
	"fmt"
	"io/ioutil"
	"net/http"
)

type apiData struct {
	contestID string
}

const findHandleBaseURL = "https://codejam.googleapis.com/scoreboard/%s/find?p=%s"

type handleSearchPayload struct {
	/*
		{"nickname":"henrybear327","scoreboard_page_size":10}
	*/
	Handle   string `json:"nickname"`
	PageSize int    `json:"scoreboard_page_size"`
}

func getHandleSearchPayload(handle string) string {
	payload := handleSearchPayload{Handle: handle, PageSize: 1}
	res, err := json.Marshal(payload)
	handleErr(err)
	return encodeToBase64(res)
}

func prettyPrint(handle string, result map[string]interface{}) {
	fmt.Println("==================================")
	if tmp, ok := result["user_scores"]; ok == false || len(tmp.([]interface{})) == 0 {
		fmt.Println(handle, "has no submission yet")
		return
	}

	// contest info
	fmt.Println("Total contestants", result["full_scoreboard_size"])
	challange := result["challenge"].(map[string]interface{})
	fmt.Println("Contest status is", challange["result_status__str"])
	fmt.Println(handle, challange["additional_info"])

	tasks := challange["tasks"].([]interface{})
	taskList := make(map[string]string)
	for _, taskObj := range tasks {
		task := taskObj.(map[string]interface{})
		taskList[task["id"].(string)] = task["title"].(string)
	}
	// for key, value := range taskList {
	// 	log.Println(key, value)
	// }

	// user info
	userScores := result["user_scores"].([]interface{})
	for _, userScoreObj := range userScores {
		userScore := userScoreObj.(map[string]interface{})
		fmt.Println("Country", userScore["country"])
		fmt.Println("Rank", userScore["rank"])
		fmt.Println("Score", userScore["score_1"])
		fmt.Println("Score 2", userScore["score_2"])

		for _, taskInfoObj := range userScore["task_info"].([]interface{}) {
			taskInfo := taskInfoObj.(map[string]interface{})
			fmt.Println("task name", taskList[taskInfo["task_id"].(string)])
			fmt.Println("total attempts", taskInfo["total_attempts"])
			fmt.Println("tasks definitely solved", taskInfo["tests_definitely_solved"])
			fmt.Println("tasks possibly solved", taskInfo["tests_possibly_solved"])
			fmt.Println("wrong attempts", taskInfo["penalty_attempts"])
		}
	}
}

func (data *apiData) getResultByHandle(handle string) {
	url := fmt.Sprintf(findHandleBaseURL, data.contestID, getHandleSearchPayload(handle))
	// log.Println("url", url)

	resp, err := http.Get(url)
	handleErr(err)
	defer resp.Body.Close()

	body, err := ioutil.ReadAll(resp.Body)
	handleErr(err)

	result := decodeFromBase64(body)
	// log.Println(string(result))

	m := make(map[string]interface{})
	err = json.Unmarshal(result, &m)
	handleErr(err)
	// log.Println(m)
	prettyPrint(handle, m)
}

func (data *apiData) getResultsByCountry(country string) {

}
