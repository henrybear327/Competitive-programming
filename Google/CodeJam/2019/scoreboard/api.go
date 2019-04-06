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
	if tmp, ok := result["user_scores"]; ok == false || len(tmp.([]interface{})) == 0 {
		fmt.Println(handle, "has no submission yet")
		return
	}

	challange := result["challenge"].(map[string]interface{})
	fmt.Println("Contest status", challange["result_status__str"])
	fmt.Println(handle, challange["additional_info"])
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
