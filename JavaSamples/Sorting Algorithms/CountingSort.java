public class CountingSort {
    int max_Range;
    int min_Range;

    public CountingSort(int min, int max){
        min_Range = min;
        max_Range = max;
    }

    public int [] perform(int arr[]){
        int n = arr.length;
 
        int second[] = new int[this.max_Range - this.min_Range + 1];
        int ret[] = new int[n];

        for(int i = 0; i < second.length; i++){
            second[i] = 0;
        }
        for(int i = 0; i < n; i++){
            int num = arr[i];
            second[num - this.min_Range]++;
        }

        for(int i = 1; i < second.length; i++){
            second[i] = second[i] + second[i - 1];
        }

        for(int i = n - 1; i >= 0; i--){
            int num = arr[i];
            int pos = second[num - this.min_Range];
            second[num - this.min_Range]--;
            ret[pos - 1] = num;
        }

        return(ret);
    }

    /*
    public static void main(String[] args) {
        int arr[] = new int[12];
        for(int i = 11; i >= 0; i--){
            arr[i] = i*i;
        }

        int ret[] = new int[12];
        CountingSort cs = new CountingSort(0, 121);
        ret = cs.perform(arr);
        for(int i = 0; i < 12; i++){
            System.out.print(ret[i] + " ");
        }
        System.out.println("");
    }
    */
}
