// npm install request; npm install promise; npm install @slack/client
const Promise = require("promise");
const request = require("request");

// let contestPhase = ["BEFORE", "CODING", "PENDING_SYSTEM_TEST", "SYSTEM_TEST", "FINISHED"];
contestPhase = ["BEFORE", "CODING", "PENDING_SYSTEM_TEST", "SYSTEM_TEST"];

const url = "http://codeforces.com/api/contest.list";

requestp = function requestp(url, json) {
    json = json || false;
    return new Promise(function (resolve, reject) {
        request({url: url, json: json, timeout: 5000}, function (error, response, body) {
            if (error) {
                return reject(error);
            } else if (response.statusCode !== 200) {
                error = new Error("Unexpected status code: " + response.statusCode);
                error.res = response;
                return reject(response);
            }
            // console.log(body);
            resolve(body);
        });
    });
};

exports.checkCodeforcesContest = function checkCodeforcesContests() {
    requestp(url, true)
        .then(function (res) {
            // console.log("Promise returned successfully");

            if(res['status'] !== "OK") {
                console.log("Status code error: %s", res['status']);
            }

            // console.log(res['result']);
            for(let contest of res['result']) {
                // console.log(contest['name']);
                if(contestPhase.includes(contest['phase'])) {
                    console.log("Contest name: %s. Phase: %s", contest['name'], contest['phase']);
                }
            }
        }, function (err) {
            console.log("Promise returned with error");

            console.error("Error: %s\nurl: %s", err.message, url);
        });
};