package relative_sort;

class solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        if(arr1.length == 0) return arr1;
        int[] map = new int[1001];
        
        for(int a: arr1) map[a]++;
        
        int i = 0;
        
        for(int b: arr2){
            while(map[b] > 0){
                arr1[i++] = b;
                map[b]--;
            }
        }
        
        
        for(int j = 0; j < 1001 && i < arr1.length;j++){
            while(map[j] > 0){
                arr1[i++] = j;
                map[j]--;
            }
            
        }
        return arr1;
    }
}