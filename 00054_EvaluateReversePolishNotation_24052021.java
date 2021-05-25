public class EvaluateReversePolishNotation {
	public static int evalRPN(String[] tokens) {
		int[] st = new int[tokens.length];
        int sp = 0;
        for (int i = 0; i < tokens.length; i ++) {
                if (tokens[i].equals("+")) {
                    int tmp = st[sp - 2] + st[sp - 1];
                    sp -= 2;
                    st[sp++] = tmp;
                } else if (tokens[i].equals("-")) {
                    int tmp = st[sp -2] - st[sp - 1];
                    sp -= 2;
                    st[sp++] = tmp;
                } else if (tokens[i].equals("*")) {
                    int tmp = st[sp -2] * st[sp - 1];
                    sp -= 2;
                    st[sp++] = tmp;
                } else if (tokens[i].equals("/")) {
                    int tmp = st[sp -2] / st[sp - 1];
                    sp -= 2;
                    st[sp++] = tmp;
                } else {
                    st[sp] = Integer.parseInt(tokens[i]);
                    sp++;
                }
        }
        return st[0];
    }
	
	public static void main(String [] args) {
		String[] arr = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
		int res = evalRPN(arr);
		System.out.println(res);
	}
}
