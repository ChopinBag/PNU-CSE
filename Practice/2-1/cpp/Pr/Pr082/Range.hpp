#ifndef RANGE_H
#define RANGE_H

class Range {
private:
    long long start_; // 시작 값
    long long stop_;  // 종료 값 (포함되지 않음)
    long long step_;  // 증가/감소 값

public:
    class Iterator {
    private:
        long long current_; // 현재 값
        long long step_;    // 증가/감소 값
        long long stop_;    // 종료 값 (비교용)

    public:
        Iterator(long long current, long long step, long long stop)
            : current_(current), step_(step), stop_(stop) {}

        long long operator*() const {
            return current_;
        }

        Iterator& operator++() {
            //Implement your code
            current_ += step_;
            return *this;
        }

        Iterator operator++(int) {
            //Implement your code
            Iterator tmp = *this;
            current_ += step_;
            return tmp;
        }

        bool operator!=(const Iterator& other) const {
            //Implement your code
            if (step_ > 0) return current_ < stop_;
            if (step_ < 0) return current_ > stop_;
        }

        bool operator==(const Iterator& other) const {
            //Implement your code
            if (step_ > 0) return current_ >= stop_;
            if (step_ < 0) return current_ <= stop_;
        }
    };

    explicit Range(long long stop);
    Range(long long start, long long stop);
    Range(long long start, long long stop, long long step);

    [[nodiscard]] Iterator begin() const;
    [[nodiscard]] Iterator end() const;

};

#endif // RANGE_H