const RtmClient = require('@slack/client').RtmClient;
const RTM_EVENTS = require('@slack/client').RTM_EVENTS;
const CLIENT_EVENTS = require('@slack/client').CLIENT_EVENTS;

/**
 * Bot Initialization Starts
 */
const bot_token = 'xoxb-232561563575-OqE28BmjVU7mmmFTzVahy6Xl';
const rtm = new RtmClient(bot_token);

let channel = 'general';

/**
 * Bot Initialization Ends
 */

const Codeforces = require('./codeforces');

// The client will emit an RTM.AUTHENTICATED event on successful connection, with the `rtm.start` payload
rtm.on(CLIENT_EVENTS.RTM.AUTHENTICATED, (rtmStartData) => {
    for (const c of rtmStartData.channels) {
        if (c.is_member && c.name === channel) {
            channel = c.id;
            console.log(`Logged in as ${rtmStartData.self.name} of team ${rtmStartData.team.name}, connected to channel ${channel}`);
            return;
        }
    }
    console.log(`Logged in as ${rtmStartData.self.name} of team ${rtmStartData.team.name}, but not yet connected to a channel`);
});

// you need to wait for the client to fully connect before you can send messages
rtm.on(CLIENT_EVENTS.RTM.RTM_CONNECTION_OPENED, function () {
    const formatted = new Date().toLocaleString();
    rtm.sendMessage(`Hello! Slack Bot on Nodejs is running (${formatted})`, channel);
});

rtm.on(RTM_EVENTS.MESSAGE, function handleRtmMessage(message) {
    console.log('Message:', message['text']); //this is no doubt the lamest possible message handler, but you get the idea
});

rtm.start();

setInterval(checkCodeforcesContests, 10000);

function checkCodeforcesContests() {
    const url = "http://codeforces.com/api/contest.list";

    Codeforces.requestp(url, true)
        .then(function (res) {
            console.log("Promise returned successfully");

            // console.log("%s@%s: %s", res.name, res.version, res.description);
            // console.log("%s", res['status']);
            if(res['status'] !== "OK") {
                console.log("Status code error: %s", res['status']);
            }

            // console.log(res['result']);
            for(let contest of res['result']) {
                // console.log(contest['name']);
                if(Codeforces.contestPhase.includes(contest['phase'])) {
                    console.log("Contest name: %s. Phase: %s", contest['name'], contest['phase']);
                }
            }
        }, function (err) {
            console.log("Promise returned with error");

            console.error("%s; %s", err.message, url);
            console.log("%j", err.res.statusCode);
        });
}