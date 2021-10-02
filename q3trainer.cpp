#include <iostream>
#include <chrono>
#include <random>
#include <ctime>

using namespace std;

int getTask(const int task)
{
    return
        task == 1 ? 35 :
        task == 0 ? 25 :
        0
    ;
}

int main(int argc, char* argv[])
{
    cout << "Quake Timing trainer\n\n";

    srand(time(NULL));
    
    int timer = 0;

    cout << "Enter timer: ";
    cin >> timer;

    int saveTimer = timer;
    int time = 0;
    int tasks = 0;
    int correct = 0;

    while(true)
    {
        if(timer <= 0) break;

        const auto startTimepoint = std::chrono::high_resolution_clock::now();

        int currentTimer = rand() % 59;
        int task = rand() % 2;
        int correctAnswer = (currentTimer + getTask(task)) > 59 ? (currentTimer + getTask(task) - 60) : (currentTimer + getTask(task));
        int answer;

        cout << currentTimer << " + " << getTask(task) << " = ";

        if(cin >> answer)
        {
            if(answer == correctAnswer)
            {
                ++correct;
            }
        }
        else
        {
            break;
        }

        ++tasks;

        auto endTimepoint = std::chrono::high_resolution_clock::now();

        long long start = std::chrono::time_point_cast<std::chrono::seconds>(startTimepoint).time_since_epoch().count();
        long long end = std::chrono::time_point_cast<std::chrono::seconds>(endTimepoint).time_since_epoch().count();

        time = (end - start);
        timer -= time;
    }

    cout.setf(ios::fixed);
    cout.precision(2);

    cout << "Average answer time: " << (saveTimer / (double)tasks) << "s.\n";
    cout << "Correct: " << correct << "/" << tasks << endl;

    return 0;
}