class Solution {
    public int gcd(int a, int b) {
        if (b == 0) return a;
        else return gcd(b, a % b);
    }

    public long solution(int w, int h) {
        long answer = 0;
        int GCD = gcd(w, h);
        int W = w / GCD, H = h / GCD;
        double tilt = (double)H / W;
        for (int i = 1; i < W; i++) {
            answer += (long) (tilt * i) - (long) (tilt * (i - 1)) + 1;
        }
        answer += H - (long)(tilt * (W-1));
        answer *= GCD;
        answer = (long)w * h - answer;
        return answer;
    }
}

