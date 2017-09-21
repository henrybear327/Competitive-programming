// npm install request; npm install promise; npm install @slack/client
const Promise = require("promise");
const request = require("request");

// let contestPhase = ["BEFORE", "CODING", "PENDING_SYSTEM_TEST", "SYSTEM_TEST", "FINISHED"];
exports.contestPhase = ["BEFORE", "CODING", "PENDING_SYSTEM_TEST", "SYSTEM_TEST"];

exports.requestp = function requestp(url, json) {
    json = json || false;
    return new Promise(function (resolve, reject) {
        request({url: url, json: json}, function (err, res, body) {
            if (err) {
                return reject(err);
            } else if (res.statusCode !== 200) {
                err = new Error("Unexpected status code: " + res.statusCode);
                err.res = res;
                return reject(err);
            }
            // console.log(body);
            resolve(body);
        });
    });
}