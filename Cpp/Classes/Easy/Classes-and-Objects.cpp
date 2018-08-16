// Write your Student class here
class Student {
private:
    vector<int> scores;
public:
    Student() {
        
    }
    void input() {
        scores = vector<int>(5);
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        scores.at(0) = a;
        scores.at(1) = b;
        scores.at(2) = c;
        scores.at(3) = d;
        scores.at(4) = e;
    }
    int calculateTotalScore() {
        if (scores.size() < 5)
            return -1;
        return scores.at(0) + scores.at(1) + scores.at(2) + scores.at(3) + scores.at(4);
    }
};
