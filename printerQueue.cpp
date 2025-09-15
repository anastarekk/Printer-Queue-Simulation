
#include <iostream>
#include <fstream>
#include<sstream>
using namespace std;

template <class T>
struct Node {
      T data;
      Node* next = nullptr;

};
template <class T>
class queue {
public:
    Node<T>* front;
    Node<T>* rear;
    queue() {
        front = nullptr;
        rear = nullptr;
    }
    void enqueue(T elem) {
        Node<T>* new_node = new Node<T>;
        new_node->data = elem;
        new_node->next = nullptr;
        if (front == nullptr) {
            front = rear = new_node;
        }
        else {
            rear->next = new_node;
            rear = new_node;
        }
    }
    void dequeue() {
        if (rear == nullptr) {
            cout<<"queue is empty!"<<endl;
        }
        else if (front == rear) {
            Node<T>* temp = front;
            front = rear = nullptr;
            delete(temp);

        }
        else {
            Node<T>* temp = front;
            front = front->next;
            delete(temp);
        }
    }
    T peek() {
        if (front == nullptr) {
            cout<<"queue is empty"<<endl;

        }
        else {
            return front->data;
        }
    }
    void display() {
        if (front == nullptr) {
            cout<<"queue is empty"<<endl;
        }
        else {
            Node<T>* ptr = front;
            while (ptr != nullptr) {
                cout<<ptr->data<<" ";
                ptr = ptr->next;
            }
        }
        cout<<endl;
    }
    bool isEmpty() {
        if (front == nullptr) {
            return true;
        }
        return false;
    }
};
int convert_to_minutes(string time) {
    stringstream ss(time);
    int hour;
    int minute;
    char colon;
    ss >> hour >> colon >> minute;
    return hour*60 + minute;
}

struct jobInfo {
    string pcName;
    string Arrtime;
    int execution_time;
    int intTime;
    int waitingTime;
};

void sortJobs(jobInfo jobs[] , int n) {
    for (int i = 0; i<n - 1;i++) {
        for (int j = 1; j < n-i ; j++) {
            if (jobs[j].intTime < jobs[j-1].intTime) {
                swap(jobs[j],jobs[j-1]);
            }
            else if (jobs[j].intTime == jobs[j-1].intTime) {
                if (jobs[j].execution_time < jobs[j-1].execution_time) {
                    swap(jobs[j],jobs[j-1]);
                }
            }
        }
    }
}

int main() {

    ifstream file("printer.txt");
    int num ;
    //input the number of printing orders
    file>>num;
    file.ignore();

    //input orders from file and store it in an array

    jobInfo orders[num];

    string pc;
    string time;
    int duration;
    for (int i = 0; i<num;i++) {
        file>>pc>>time>>duration;
        orders[i].pcName = pc;
        orders[i].Arrtime = time;
        orders[i].execution_time = duration;
        orders[i].intTime = convert_to_minutes(time);
    }

sortJobs(orders,num);
    queue<jobInfo> printerQueue;
    for (int i = 0; i < num; i++) {
        printerQueue.enqueue(orders[i]);
    }

    int currentTime = 0;
    float totalWaitingTime = 0;
    int totalExecutionTime = 0;
    int jobsExecuted = 0;

    cout << "Jobs Executed: " << num << endl;

    while (!printerQueue.isEmpty()) {
        jobInfo job = printerQueue.peek();
        printerQueue.dequeue();

        if (currentTime < job.intTime)
            currentTime = job.intTime;

        int waitingTime = currentTime - job.intTime;
        int startTime = currentTime;
        currentTime += job.execution_time;
        totalWaitingTime += waitingTime;
        totalExecutionTime += job.execution_time;

        int hr = startTime / 60;
        int min = startTime % 60;

        cout << job.pcName << " " << job.Arrtime << " " << job.execution_time
             << " executed at "  << hr << ":"<< min
             << " waiting time: " << waitingTime << endl;
        jobsExecuted++;
    }

    cout << "The printer was occupied for " << totalExecutionTime << " minutes"<<endl;
    cout << "Average waiting time for all jobs is " << totalWaitingTime / jobsExecuted << " minutes"<<endl;

    return 0;
}