import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class FindDuplicateFileInSystem {
	public static List<List<String> > findDuplicate(String[] paths){
		List<List<String> > ans = new ArrayList<List<String>>();
		if(paths == null || paths.length == 0) return ans;
		
		Map<String, List<String> > hashMap = new HashMap<String, List<String>>();
		
		for(String item : paths) {
			// Split item into separate file paths
			String[] parts = item.split(" ");
			
			for(int i = 1; i < parts.length; ++i) {
				// Find index of "(" element to split parts[i] in order to content and path
				int index = parts[i].indexOf('(');
				String content = parts[i].substring(index + 1, parts[i].length() - 1);
                String path = parts[0] + "/" + parts[i].substring(0, index);
				if(hashMap.containsKey(content)) {
					hashMap.get(content).add(path);
				}
				else {
					// We can't add path directly to hashMap because we need to add List<String> not a String Object
					List<String> temp = new ArrayList<>();
					temp.add(path);
					hashMap.put(content, temp);
				}
			}
			// Use hashMap.entrySet() to turn {20=Geeks, 25=Welcomes, 10=Geeks, 30=You, 15=4} into [20=Geeks, 25=Welcomes, 10=Geeks, 30=You, 15=4]
			// Mapping to the set
			for(Map.Entry<String, List<String> > entry : hashMap.entrySet()) {
				List<String> value = entry.getValue();
				if(value.size() > 1) {
					List<String> tmp = new ArrayList<>();
					for(String cur : value) {
						tmp.add(cur);
					}
					ans.add(tmp);
				}
			}
			
		}
		return ans;
	}
	
	public static void print(List<List<String> > ans) {
		for(List<String> curList : ans) {
			for(String curString : curList) {
				System.out.print(curString + " + ");
			}
			System.out.println("");
		}
	}
	
	public static void main(String[] args) {
		String[] paths1 = {"root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)"};
		String[] paths2 = {"root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)"};
		
		List<List<String> > ans1 = findDuplicate(paths1);
		List<List<String> > ans2 = findDuplicate(paths2);
		
		print(ans1);
		print(ans2);
	}
}

// https://leetcode.com/problems/find-duplicate-file-in-system/