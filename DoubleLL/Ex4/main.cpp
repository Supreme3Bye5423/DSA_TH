#include <iostream>
#include <list>

using namespace std;

class DataLog
{
private:
    list<int> logList;
    list<int>::iterator currentState;

public:
    DataLog();
    DataLog(const int &data);
    void addCurrentState(int number);
    void subtractCurrentState(int number);
    void save();
    void undo();
    void redo();

    int getCurrentStateData()
    {
        return *currentState;
    }

    void printLog()
    {
        for (auto i = logList.begin(); i != logList.end(); i++) {
            if(i == currentState) {
                cout << "Current state: ";
            }
            cout << "[ " << *i << " ] => ";
        }
        cout << "END_LOG";
    }
};

int i;

DataLog::DataLog()
{
    /*
     * TODO:  add the first state with 0
     */
    logList.push_back(0);
    currentState = logList.begin();
    i = 0;
}

DataLog::DataLog(const int &data)
{
    /*
     * TODO:  add the first state with data
     */
    logList.push_back(data);
    currentState = logList.begin();
    i = 0;
}

void DataLog::addCurrentState(int number)
{
    /*
     * TODO: Increase the value of current state by number
     */
    *currentState += number;
}

void DataLog::subtractCurrentState(int number)
{
    /*
     * TODO: Decrease the value of current state by number
     */
    *currentState -= number;
}

void DataLog::save()
{
    /*
     * TODO: This function will create a new state, copy the data of the currentState
     *       and move the currentState Iterator to this new state. If there are other states behind the
     *       currentState Iterator, we delete them all before creating a new state.
     */
    int size = (int)logList.size();
    for(int j = i; j < size - 1;j++)
    {
        logList.pop_back();
    }
    logList.push_back(*currentState);
    currentState++;
    i++;
}

void DataLog::undo()
{
    /*
     * TODO: Switch to the previous state of the data
     *       If this is the oldest state in the log, nothing changes
     */
    if (currentState != logList.begin()) {
        currentState--;
        i--;
    }
}

void DataLog::redo()
{
    /*
     * TODO: Switch to the latter state of the data
     *       If this is the latest state in the log, nothing changes
     */
    int size = (int)logList.size();
    if (i < size - 1) {
        currentState++;
        i++;
    }
}


int main() {
    DataLog log(10);
    log.save();
    log.addCurrentState(15);
    log.save();
    log.addCurrentState(15);
    log.save();
    log.save();
    log.undo();
    log.redo();
    log.printLog();
    cout << "\n";
    log.redo();
    log.printLog();
}
