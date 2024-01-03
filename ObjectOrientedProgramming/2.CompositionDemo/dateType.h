#ifndef H_dateType
#define H_dateType

class dateType {
    public:
        // Function to set the date
        void setDate(int day, int month, int year);

        // Function to return the day
        int getDay() const;

        // Function to return the month
        int getMonth() const;

        // Function to return the year
        int getYear() const;

        // Function to print the date in the format "dd-mm-yyyy"
        void printDate() const;

        // Constructor to set the default date
        dateType(int day = 1, int month = 1, int year = 1900);

    private:
        int dDay;
        int dMonth;
        int dYear;
};

#endif