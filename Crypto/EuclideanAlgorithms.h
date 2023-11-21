class EuclideanAlgorithms {
public:
    int getDivisorWithSubtraction(int a, int b) {
        a = a < 0 ? -a : a;
        b = b < 0 ? -b : b;
        while (a != b) {
            if (a > b) {
                a -= b;
            }
            else {
                b -= a;
            }
        }
        return a;
    }
    int getDivisorWithDivision(int a, int b) {
        a = a < 0 ? -a : a;
        b = b < 0 ? -b : b;
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    int getSmallestMultiple(int a, int b) {
        if (a == 0 || b == 0) {
            return 0;
        }
        int divisor = getDivisorWithDivision(a, b);
        int multiple = (a * b) / divisor;
        return multiple;
    }
};
