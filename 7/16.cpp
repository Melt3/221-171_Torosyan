#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Lecture {
    int start;
    int end;
};

bool compareLectures(const Lecture& a, const Lecture& b) {
    return a.end < b.end;
}

int main() {
    int N;
    cin >> N;
    
    vector<Lecture> lectures(N);
    for (int i = 0; i < N; ++i) {
        cin >> lectures[i].start >> lectures[i].end;
    }
    
    sort(lectures.begin(), lectures.end(), compareLectures);
    
    int count = 0;
    int current_end = 0;
    
    for (const auto& lecture : lectures) {
        if (lecture.start >= current_end) {
            ++count;
            current_end = lecture.end;
        }
    }
    
    cout << count << endl;
    
    return 0;
}
