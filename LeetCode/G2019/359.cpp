class Logger
{
private:
    unordered_map<string, int> data;

public:
    /** Initialize your data structure here. */
    Logger() {}

    /** Returns true if the message should be printed in the given timestamp,
       otherwise returns false. If this method returns false, the message will not
       be printed. The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message)
    {
        if (data.find(message) == data.end()) {
            data[message] = timestamp;
            return true;
        } else {
            int t = data[message];
            if (timestamp - t < 10) {
                // data[message].insert(timestamp);
                return false;
            } else {
                data[message] = timestamp;
                return true;
            }
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */
