import java.util.Scanner;

class TreeHolder{
    int numberOfVertices;
    
    public TreeHolder(int n){
        numberOfVertices = n;
    }

    public void dijkstraAlgorithm(int mat[][], int start, double betweennessCentrality[]){
        int storage[][] = new int[numberOfVertices][numberOfVertices];
        int count = 0;

        int container[] = new int[numberOfVertices];
        container[start] = count + 1;
        int beginning = start;

        int i;
        for(i = 0; i < numberOfVertices; i++){
            if(mat[start][i] > 0){
                storage[count][i] = mat[start][i];
            }else{
                storage[count][i] = 2100000000;
            }
        }
        count = count + 1;

        while(start < numberOfVertices){
            for(i = 0; i < numberOfVertices; i++){
                if(container[i] == 0 && (storage[count - 1][i] < storage[count - 1][start])){
                    start = i;
                }
            }

            container[start] =  count + 1;

            for(i = 0; i < numberOfVertices; i++){
                if(container[i] == 0 && mat[start][i] > 0){
                    if((storage[count - 1][start] + mat[start][i]) < storage[count - 1][i]){
                        storage[count][i] = storage[count - 1][start] + mat[start][i];
                    }else{
                        storage[count][i] = storage[count - 1][i];
                    }
                }else{
                    storage[count][i] = storage[count - 1][i];
                }
            }

            count = count + 1;

            int w = 0;
            while(w < numberOfVertices && container[w] != 0){
                w = w + 1;
            }
            start = w;
        }

        int h;
        for(h = 0; h < numberOfVertices; h++){
            long totalShortestPath = 0;
            long occurence[] = new long[numberOfVertices];

            if(h == beginning){
                continue;
            }else{
                int contain[] = new int[numberOfVertices + 1];
                contain[0] = beginning;
                contain[numberOfVertices] = 1;

                int mainStorage[][] = new int[numberOfVertices*numberOfVertices*numberOfVertices*numberOfVertices][numberOfVertices + 1];
                int pos[] = new int[1];
                pos[0] = 0;

                findAllShortestPath(mat, contain, beginning, h, mainStorage, pos);
                int t;

                totalShortestPath = editOccurence(h, container, mat, storage, mainStorage, pos, occurence);
    
                for(t = 0; t < numberOfVertices; t++){
                    double xyz;
                    xyz = (double)((double)(occurence[t])/(double)(2*totalShortestPath));
                    betweennessCentrality[t] = betweennessCentrality[t] + xyz;

                }
                
            }
        }
    }

    public long editOccurence(int h, int container[], int mat[][], int storage[][], int mainStorage[][], int pos[], long occurence[]){
        int t;
        long pathQunatity = 0;
        int path = 0;
        int s;

        for(t = 0; t < pos[0]; t++){
            for(s = 1; s < mainStorage[t][numberOfVertices]; s++){
                int u = mainStorage[t][s - 1];
                int v = mainStorage[t][s];
                path = path + mat[u][v];
            }
        
            if(path == storage[container[h] - 2][h]){
                pathQunatity = pathQunatity + 1;
                int var = 1;
                for(var = 1; var < ((mainStorage[t][numberOfVertices]) - 1); var++){
                    int value = mainStorage[t][var];
                    occurence[value] = occurence[value] + 1;
                }
            }
            path = 0;
        }

        return(pathQunatity);
    }

    public void findAllShortestPath(int mat[][], int container[], int start, int end, int mainStorage[][], int pos[]){
        int i;
        for(i = 0; i < numberOfVertices; i++){
            if(mat[start][i] > 0){
                int k;
                for(k = 0; k < container[numberOfVertices]; k++){
                    if(container[k] == i){
                        break;
                    }
                }
                if(k < container[numberOfVertices]){
                    continue;
                }else if(i == end){
                    for(k = 0; k < container[numberOfVertices]; k++){
                        mainStorage[pos[0]][k] = container[k];
                    }
                    mainStorage[pos[0]][k] = end;
                    mainStorage[pos[0]][numberOfVertices] = container[numberOfVertices] + 1;
                    pos[0] = pos[0] + 1;
                }else{
                    int ct[] = new int[numberOfVertices + 1];
                    int j;
                    for(j = 0; j < container[numberOfVertices]; j++){
                        ct[j] = container[j];
                    }
                    ct[j] = i;
                    ct[numberOfVertices] = container[numberOfVertices] + 1;
                    findAllShortestPath(mat, ct, i, end, mainStorage, pos);
                }
            }
        }
    }

    public void findBetweennessCentrality(int mat[][]){
        int i = 0;
        double betweennessCentrality[] = new double[numberOfVertices];
        for(i = 0; i < numberOfVertices; i++){
            dijkstraAlgorithm(mat, i, betweennessCentrality);
        }
        for(i = 0; i < numberOfVertices; i++){
            System.out.print(betweennessCentrality[i] + " ");
        }
        System.out.println("");
    }

}

class P1{
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int v = sc.nextInt();

        int mat[][] = new int[n][n];
        int i;
        for(i = 0; i < v; i++){
            int u1 = sc.nextInt();
            int u2 = sc.nextInt();
            int w = sc.nextInt();

            mat[u1][u2] = w;
            mat[u2][u1] = w;
        }

        TreeHolder tree = new TreeHolder(n);
        tree.findBetweennessCentrality(mat);
    }
}