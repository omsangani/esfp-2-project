#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <sstream>
                                           
using namespace std;

// alarm clock class

class alarm
{
private:
    tm askedTime, c_time, diff_In_Time;
    time_t now;

public:
    
    // constructor of the class

    alarm()
    {
        now = time(0);
        c_time = *localtime(&now);
        askedTime = c_time;
        askedTime.tm_sec = 0;
    }

    // function to take input from the user.

    void getTime()
    {
        string Time;
        system("clear");
        cout << "\t---------------------WELCOME---------------------\n";
        cout << "\t|                                               |\n";
        cout << "\t| Simple Alarm Clock using C++                  |\n";
        cout << "\t|\t\tProject done by Om Sangani.     |\n";
        cout << "\t|                                               |\n";
        cout << "\t| Enter time in 24-hour format :                |\n";
        cout << "\t| HH:MM >>> ";
        getline(cin, Time);
        cout << "\t|_______________________________________________|\n";
        int pos = 0, h;
        while ((pos = Time.find(':')) != string::npos)
        {
            string token = Time.substr(0, pos);
            stringstream convert(token);
            convert >> askedTime.tm_hour;
            Time.erase(0, pos + 1);
        }
        stringstream convert(Time);
        convert >> askedTime.tm_min;
    }
    
    // function to calculate difference between current time and asked time.
    
    void timeDifference() 
    {
        int seconds = difftime(mktime(&askedTime), now);
        diff_In_Time.tm_min = seconds / 60;
        diff_In_Time.tm_hour = diff_In_Time.tm_min / 60;
        diff_In_Time.tm_min = diff_In_Time.tm_min % 60;
        diff_In_Time.tm_sec = seconds % 60;
        if (seconds < 0)
        {
            diff_In_Time.tm_hour = 24 + diff_In_Time.tm_hour - 1;
            diff_In_Time.tm_min = 0 - diff_In_Time.tm_min;
            diff_In_Time.tm_sec = 0 - diff_In_Time.tm_sec;
        }
    }

    // function to start alarm and print the time reaming to hit the desired time.

    void start_alarm()
    {
        while (true)
        {
            now = time(0);
            c_time = *localtime(&now);
            timeDifference();
            cout << "TIME REMAINING:    " << diff_In_Time.tm_hour << ":" << diff_In_Time.tm_min << ":" << diff_In_Time.tm_sec << endl;
            system("sleep 1");
            if (diff_In_Time.tm_hour == 0 && diff_In_Time.tm_min == 0 && diff_In_Time.tm_sec == 0)
            {
                cout << endl
                     << "Time Completed" << endl
                     << ">>> PRESS CTRL+C or Click on CROSS BUTTON to stop the alarm <<<" << endl;
                break;
            }
        }
    }
};

int main()
{
    alarm A;
    A.getTime();
    A.start_alarm();
    for (int i = 0;; i = i + 50)
        system("play /home/venom/Downloads/sample3.ogg");
    return 0;
}