#include<iostream>
using namespace std;

template<class T>
class Queue
{
    public :
        int front;
        int rear;
        T arr[5];

        Queue(){ front=0; rear=0;}

        void enqueue(T data)
        {
            if(rear==4) {
                cout<<"Queue is Full "<<endl;
            }
            else{
                arr[rear]=data;
                rear++;
            }
        }

        void dequeue()
        {
            if(front==rear) {
                cout<<"Queue is Empty "<<endl;
            }
            else{ 
                T temp=arr[front];
                arr[front]=0;
                front++;
                cout<<"Element : " << temp<< " is been dequeued"<<endl;
            }
           
        }

        T peek()
        {
            return arr[front];
        }

};

int main()
{
    Queue<double> q1;
    q1.enqueue(11.11);
    q1.enqueue(22.22);
    q1.enqueue(33.33);
    q1.enqueue(44.44);

    double data=q1.peek();
    
    cout<<"Value at Front : "<<data<<endl;
    q1.dequeue();


    cout<<"Value at Front : "<<data<<endl;
    q1.dequeue();


    cout<<"Value at Front : "<<data<<endl;
        q1.dequeue();
        q1.dequeue();
        q1.dequeue();     
}
