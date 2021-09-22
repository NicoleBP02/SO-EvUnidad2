public class Problema1 {
    public static void main(String[] args) {
        IntArray myarr = new IntArray();
        initIntArray(myarr);
        printArray(myarr);

    }

    IntArray createIntArray(int size) {
        // Esto no es necesario pues es manejado por el new
        return null;
    }

    static void initIntArray(IntArray that) {

        for (int i = 0; i < that.length; i++) {
            that.arr[i] = i;
        }

    }

    static void printArray(IntArray that) {
        for (int i = 0; i < that.length; i++) {
            System.out.println("that.arr[" + i + "] = " + that.arr[i]);
        }
    }

    void destroyIntArray(IntArray that) {
        // Java posee un garbage collector que realiza esta tarea
        // automáticamente
    }
}
