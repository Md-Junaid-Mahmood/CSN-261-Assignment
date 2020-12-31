import java.util.Scanner;

class P2{
    private static void createPostOrder(int preOrder[], int inOrder[], int start, int end, int top, int bottom, int post[], int pos[]){
        int root = preOrder[start];
        int i;

        int left = 0;
        for(i = top; i <= bottom; i++){
            if(inOrder[i] == root){
                break;
            }
            left = left + 1;
        }
        if(left == 1){
            post[pos[0]] = inOrder[top];
            pos[0] = pos[0] + 1;
        }else if(left != 0){
            createPostOrder(preOrder, inOrder, start + 1, start + left, top, i - 1, post, pos);
        }
        
        int right = 0;
        for(i = bottom; i >= top; i--){
            if(inOrder[i] == root){
                break;
            }
            right = right + 1;
        }
        if(right == 1){
            post[pos[0]] = inOrder[bottom];
            pos[0] = pos[0] + 1;
        }else if(right != 0){
            createPostOrder(preOrder, inOrder, start + left + 1, end, i + 1, bottom, post, pos);
        }

        post[pos[0]] = root;
        pos[0] = pos[0] + 1;
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int inOrder[] = new int[n];
        int preOrder[] = new int[n];
        int postOrder[] = new int[n];
        int pos[] = new int[1];
        pos[0] = 0;
        int i;

        for(i = 0; i < n; i++){
            inOrder[i] = sc.nextInt();
        }

        for(i = 0; i < n; i++){
            preOrder[i] = sc.nextInt();
        }

        createPostOrder(preOrder, inOrder, 0, n-1, 0, n-1, postOrder, pos);
        for(i = 0; i < n; i++){
            System.out.print(postOrder[i] + " ");
        }
        System.out.println("");
    }
}