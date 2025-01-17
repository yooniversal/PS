class Solution {
    public boolean doesValidArrayExist(int[] derived) {
        int prev = 0;
        int[] arr = new int[derived.length];

        for (int i=0; i<derived.length-1; i++) {
            if (derived[i] == 0) {
                arr[i+1] = prev;
            } else {
                arr[i+1] = prev ^ 1;
                prev = prev ^ 1;
            }
        }

        if (validate(derived, arr)) return true;

        for (int i=0; i<derived.length; i++) arr[i] = 1;
        prev = 1;

        for (int i=0; i<derived.length-1; i++) {
            if (derived[i] == 0) {
                arr[i+1] = prev;
            } else {
                arr[i+1] = prev ^ 1;
                prev = prev ^ 1;
            }
        }

        return validate(derived, arr);
    }

    public boolean validate(int[] derived, int[] arr) {
        for (int i=0; i<arr.length; i++) {
            if (i < arr.length-1) {
                if ((arr[i] ^ arr[i+1]) != derived[i]) return false;
            } else {
                if ((arr[i] ^ arr[0]) != derived[i]) return false;
            }
        }
        return true;
    }
}