
    #include <iostream>

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

        double brokerage = calculateBrokerage(bp, sp);
        cout << "Total Brokerage :" << brokerage << endl;

        double st = calculate_st(brokerage);
        cout << "Total Service Tax:" << st << endl;

        double stt = calculateSTT(sp);
        cout << "Total STT :" << stt << endl;

        double sd = calculate_sd(sp, bp);
        cout << "Total Stamp Deuty :" << sd << endl;

        double rc = calculate_rc(sp, bp);
        cout << "Total Regulatory Charges:" << rc << endl;

        double tc = totalc(brokerage, st, stt, sd, rc);
        double total = calculateProfit(sp, bp, tc);
        cout << "Your total profit is :" << total << endl;

        return 0;
    }

