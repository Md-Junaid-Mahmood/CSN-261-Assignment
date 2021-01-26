import java.util.Scanner;

class P3{
    public static int totalPricePaid = 2100000000;

    public static void doDijkstraAlgorithm(int n, int mat[][], int start, int end, int fuel[], int cost, int initialFuelValue){
        int fuelPriceContainer[] = new int[n];
        int i;
        for(i = 0; i < n; i++){
            fuelPriceContainer[i] = initialFuelValue;
        }
        int storage[][] = new int[n][n];
        int count = 0;

        int container[] = new int[n];
        container[start] = 1;
        for(i = 0; i < n; i++){
            if(mat[start][i] > 0){
                storage[count][i] = mat[start][i]*fuelPriceContainer[i];
            }else{
                storage[count][i] = 2100000000;
            }
        }

        for(count = 1; count < n; count++){
            for(i = 0; i < n; i++){
                if(container[i] == 0){
                    start = i;
                    break;
                }
            }
            for(i = 0; i < n; i++){
                if(container[i] == 0 && (storage[count - 1][i] < storage[count - 1][start])){
                    start = i;
                }
            }
            container[start] = 1;

            if(fuelPriceContainer[start] > fuel[start]){
                fuelPriceContainer[start] = fuel[start];
            }


            for(i = 0; i < n; i++){
                if(container[i] == 0 && mat[start][i] > 0){
                    int originalFuel = fuelPriceContainer[i];
                    if(fuelPriceContainer[i] > fuelPriceContainer[start]){
                        fuelPriceContainer[i] = fuelPriceContainer[start];
                    }
                    int value = (storage[count - 1][start] + (mat[start][i] * fuelPriceContainer[i]));
                    if(value < storage[count - 1][i]){
                        storage[count][i] = value;
                    }else{
                        storage[count][i] = storage[count - 1][i];
                        fuelPriceContainer[i] = originalFuel;
                    }
                }else{
                    storage[count][i] = storage[count - 1][i];
                }
            }
        }

        if((cost + storage[n - 1][end]) < totalPricePaid){
            totalPricePaid = cost + storage[n - 1][end];
        }

        for(i = 0; i < n; i++){
            int val = cost + storage[n - 1][i];
            if(val < totalPricePaid){
                doDijkstraAlgorithm(n, mat, i, end, fuel, val, fuelPriceContainer[i]);
            }
        }
    }

    public static void printCost(){
        System.out.println(totalPricePaid + " ");
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        int i;
        for(i = 0; i < t; i++){
            int n = sc.nextInt();
            int r = sc.nextInt();
            int mat[][] = new int[n][n];
            int j;
            for(j = 0; j < r; j++){
                int u = sc.nextInt();
                int v = sc.nextInt();
                int w = sc.nextInt();

                u = u - 1;
                v = v - 1;
                mat[u][v] = w;
                mat[v][u] = w;
            }

            int fuel[] = new int[n];
            for(j = 0; j < n; j++){
                fuel[j] = sc.nextInt();
            }

            int start = sc.nextInt();
            int end = sc.nextInt();

            start = start - 1;
            end = end - 1;

            doDijkstraAlgorithm(n, mat, start, end, fuel, 0, fuel[start]);
            printCost();
        }
    }
}