class Solution {

    private int[] uni;

    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        Map<Integer, String> usernameById = new HashMap<>();
        Map<String, Integer> userByEmail = new HashMap<>();
        Map<Integer, List<String>> emailListOnId = new HashMap<>();

        uni = new int[1005];
        for (int i=0; i<1005; i++) uni[i] = i;
        
        int globalId = 0;

        for (List<String> a : accounts) {
            String name = a.get(0);

            List<Integer> ids = new ArrayList<>();
            for (int i=1; i<a.size(); i++) {
                String email = a.get(i);
                if (userByEmail.containsKey(email)) {
                    ids.add(userByEmail.get(email));
                }
            }

            if (!ids.isEmpty()) {
                for (int i=0; i<ids.size()-1; i++) {
                    makeUnion(ids.get(i), ids.get(i+1));
                }
                int id = ids.get(0);
                
                List<String> emailList = emailListOnId.get(id);

                for (int i=1; i<a.size(); i++) {
                    String email = a.get(i);
                    if (!userByEmail.containsKey(email)) {
                        userByEmail.put(email, id);
                        emailList.add(email);
                    }
                }
            } else {
                int id = globalId++;
                List<String> emailList = new ArrayList<>();

                for (int i=1; i<a.size(); i++) {
                    String email = a.get(i);
                    userByEmail.put(email, id);
                    emailList.add(email);
                }

                usernameById.put(id, name);
                emailListOnId.put(id, emailList);
            }
        }

        // 부모 email list에 모두 추가
        for (Map.Entry<Integer, List<String>> entry : emailListOnId.entrySet()) {
            int id = entry.getKey();
            List<String> emailList = entry.getValue();

            int parentId = find(id);
            if (parentId == id) continue;

            List<String> parentEmailList = emailListOnId.get(parentId);
            parentEmailList.addAll(emailList);
            emailListOnId.put(parentId, parentEmailList);
        }

        List<List<String>> ret = new ArrayList<>();

        // 부모 email list만 처리
        for (Map.Entry<Integer, List<String>> entry : emailListOnId.entrySet()) {
            int id = entry.getKey();
            List<String> emailList = entry.getValue();

            int parentId = find(id);
            if (parentId != id) continue;
            
            emailList = emailList.stream()
                .distinct()
                .sorted()
                .toList();

            List<String> newAccount = new ArrayList<>();
            newAccount.add(usernameById.get(id));
            newAccount.addAll(emailList);

            ret.add(newAccount);
        }
        ret.sort((a, b) -> a.get(0).compareTo(b.get(0)));

        return ret;
    }

    private int find(int x) {
        if (uni[x] == x) return x;
        return uni[x] = find(uni[x]);
    }

    private void makeUnion(int x, int y) {
        int px = find(x), py = find(y);

        if (px < py) {
            uni[py] = px;
        } else {
            uni[px] = py;
        }
    }
}
