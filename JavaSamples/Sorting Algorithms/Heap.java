import java.util.ArrayList;

public class Heap {
    private ArrayList<Integer> minHeap = new ArrayList<Integer>();
    private int count;

    public Heap(){
        count = -1;
    }
    public void initialAdd(int num){
        minHeap.add(num);
        count++;
    }

    public int getCount(){
        return(this.count);
    }

    public void heapify(int position){
        int left = 2*position + 1;
        int right = 2*position + 2;
        if(left > count){
            return;
        }else if(right > count){
            if(minHeap.get(left) < minHeap.get(position)){
                int temp1 = minHeap.get(left);
                int temp2 = minHeap.get(position);
                minHeap.set(left, temp2);
                minHeap.set(position, temp1);
                heapify(left);
            }
        }else{
            int index = left;
            if(minHeap.get(right) < minHeap.get(left)){
                index = right;
            }
            if(minHeap.get(index) < minHeap.get(position)){
                int temp1 = minHeap.get(index);
                int temp2 = minHeap.get(position);
                minHeap.set(index, temp2);
                minHeap.set(position, temp1);
                heapify(index);
            }
        }
    }

    public int poll(){
        int num = minHeap.get(0);
        minHeap.set(0, minHeap.get(count));
        minHeap.set(count, 0);
        count--;
        heapify(0);
        return(num);
    }

    public int peek(){
        return(minHeap.get(0));
    }

    public void add(int num){
        count++;
        int child = count;
        if(minHeap.size() == count){
            minHeap.add(num);
        }else{
            minHeap.set(count, num);
        }

        int parent = (int)(child/2);
        if(child%2 == 0){
            parent--;
        }
        while(parent >= 0){
            if(minHeap.get(parent) > minHeap.get(child)){
                int temp1 = minHeap.get(child);
                int temp2 = minHeap.get(parent);

                minHeap.set(child, temp2);
                minHeap.set(parent, temp1);
            }else{
                break;
            }

            child = parent;
            parent = (int)(child/2);
            if(child%2 == 0){
                parent--;
            }
        }
    }
}
