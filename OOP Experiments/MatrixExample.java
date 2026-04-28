class MatrixExample {
    public static void main(String[] args) {

        // Declaration
        int[][] m;

        // Creation
        m = new int[3][3];

        // Assign values
        for (int i = 0; i < m.length; i++) {
            for (int j = 0; j < m[i].length; j++) {
                m[i][j] = i + j;
            }
        }

        // Access elements
        for (int i = 0; i < m.length; i++) {
            for (int j = 0; j < m[i].length; j++) {
                System.out.println(m[i][j]);
            }
        }
    }
}