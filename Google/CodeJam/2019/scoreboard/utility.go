package main

import (
	"encoding/base64"
	"log"
)

func handleErr(err error) {
	if err != nil {
		log.Fatalln("error:", err)
	}
}

func encodeToBase64(input []byte) string {
	str := base64.URLEncoding.EncodeToString(input)
	return str
}

func decodeFromBase64(input []byte) []byte {
	res := make([]byte, len(input))
	n, err := base64.RawURLEncoding.Decode(res, input)
	handleErr(err)
	return res[:n]
}
