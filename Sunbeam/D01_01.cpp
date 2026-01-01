
    #include <iostream>
    #include<iomanip>

    using namespace std;

    double calculateBrokerage(double bp, double sp) {
        return (bp * 0.003) + (sp * 0.003);
    }

    double calculate_st(double brokerage) {
        return brokerage * 0.1036;
    }

    double calculateSTT(double sp) {
        return sp * 0.0025;
    }

    double calculate_sd(double sp, double bp) {
        return (sp - bp) * 0.0002;
    }

    double calculate_rc(double sp, double bp) {
        return (sp - bp) * 0.0004;
    }

    double totalc(double brokerage, double st, double stt, double sd, double rc) {
        return brokerage + st + stt + sd + rc;
    }

    double calculateProfit(double sp, double bp, double tc) {
        return sp - bp - tc;
    }

    int main() {
        double bp, sp;

        cout << "Enter buying price of stock :" << endl;
        cin >> bp;

        cout << "Enter the selling price of stock :" << endl;
        cin >> sp;
        cout << setw(30) <<"Share Trading Statement"<< endl;

            double brokerage = calculateBrokerage(bp, sp);
            cout << setw(30) << left << "Total Brokerage :" <<   setw(10)  << brokerage << endl;

            double st = calculate_st(brokerage);
            cout << setw(30) << left << "Total Service Tax:" <<  setfill('.')<<  setw(10)  << st << endl;

            double stt = calculateSTT(sp);
            cout << setw(30) << left << "Total STT :" <<  setw(10)<< stt << endl;

            double sd = calculate_sd(sp, bp);
            cout << setw(30) << left << "Total Stamp Duty :" <<  setw(10) << sd << endl;

            double rc = calculate_rc(sp, bp);
            cout << setw(30) << left << "Total Regulatory Charges:" << setw(10) <<  rc << endl;

            double tc = totalc(brokerage, st, stt, sd, rc);
            double total = calculateProfit(sp, bp, tc);
            cout << setw(30) << left << "Your total profit is :" <<  setw(10) <<  total << endl;      return 0;
    }

