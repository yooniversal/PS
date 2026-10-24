
class Solution {
    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
        Arrays.sort(products);

        Map<String, List<String>> map = new HashMap<>();

        for (String product : products) {
            for (int i = 1; i <= product.length(); i++) {
                String prefix = product.substring(0, i);

                List<String> list = map.computeIfAbsent(
                    prefix, k -> new ArrayList<>()
                );

                if (list.size() < 3) {
                    list.add(product);
                }
            }
        }

        List<List<String>> ret = new ArrayList<>();

        for (int i = 1; i <= searchWord.length(); i++) {
            String prefix = searchWord.substring(0, i);

            ret.add(map.getOrDefault(prefix, Collections.emptyList()));
        }

        return ret;
    }
}
