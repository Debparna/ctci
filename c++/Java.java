/*
compile: javac Java.java
run: java Java
java -cp . Example_16/Example

Arrays:
dataType[] arrayRefVar;   // preferred way.
arrayRefVar = new dataType[arraySize];
*/

//MergeSort
class MergeSort
{
    void merge(int arr[], int l, int m, int r)
    {
        // Find sizes of two subarrays to be merged
        int n1 = m - l + 1;
        int n2 = r - m;

        /* Create temp arrays */
        int L[] = new int [n1];
        int R[] = new int [n2];

        /*Copy data to temp arrays*/
        for (int i=0; i<n1; ++i)
            L[i] = arr[l + i];
        for (int j=0; j<n2; ++j)
            R[j] = arr[m + 1+ j];

        /* Merge the temp arrays */

        // Initial indexes of first and second subarrays
        int i = 0, j = 0;

        // Initial index of merged subarry array
        int k = l;
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        /* Copy remaining elements of L[] if any */
        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }

        /* Copy remaining elements of R[] if any */
        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    void sort(int arr[], int l, int r)
    {
        if (l < r)
        {
            // Find the middle point
            int m = (l+r)/2;

            // Sort first and second halves
            sort(arr, l, m);
            sort(arr , m+1, r);

            // Merge the sorted halves
            merge(arr, l, m, r);
        }
    }

    /* A utility function to print array of size n */
    static void printArray(int arr[])
    {
        int n = arr.length;
        for (int i=0; i<n; ++i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }

    // Driver method
    public static void main(String args[])
    {
        int arr[] = {12, 11, 13, 5, 6, 7};

        System.out.println("Given Array");
        printArray(arr);

        MergeSort ob = new MergeSort();
        ob.sort(arr, 0, arr.length-1);

        System.out.println("\nSorted array");
        printArray(arr);
    }
}

public static class Node{
  Node next;
  int data;
  public Node(int data){
    this.data = data;
  }
}

public class linkedlist{
  Node head;

  public void append(int data){
    if(head == null){
      head = new Node(data);
    }
    Node current = head;
    while(current.next != null){
      current = current.next;
    }
    current.next = new node(data);
  }

  public void prepend(int data){
    Node newHead = new Node(data);
    newHead.next = head;
    head = newHead;
  }

  public void deleteWithValue(int data){
    if(head == null) return;
    if(head.data = data){
      head = head.next;
      return;
    }

    Node current = head;
    while(current.next ! = null){
      if(current.next.data == data){
        current.next = current.next.next;
        return;
      }
      current = current.next;
    }
  }
}

public class Stack{
  private static class Node{
    private int data;
    private node next;
    private node(int data){
      this.data = data;
    }
  }

  private Node top;

  public boolean isEmpty(){
    return top == null;
  }

  public int peek(){
    return top.data;
  }

  public void push(int data){
    Node node = new Node(data);
    node.next = top;
    top = node;
  }

  public int pop(){
    int data = top.data;
    top = top.next;
    return data;
  }
}

public static class Queue{
  private static class Node{
    private int data;
    private node next;
    private node(int data){
      this.data = data;
    }
  }

  private Node head;
  private Node tail;

  public boolean isEmpty(){
    return head == null;
  }

  public int peek(){
    return head.date;
  }

  public void add(int data){
    Node node = new Node(data);
    if(tail != null){
      tail.next = node;
    }
    tail = node;
    if(head != null){
      head = node;
    }
  }

  public void remove(int data){
    int data = head.data;
    head = head.next;
    if(head == null){
      tail = next;
    }
    return data;
  }
}
