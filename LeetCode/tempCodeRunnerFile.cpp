 {
// public:

    
//     // Encodes a tree to a single string.
//     string serialize(TreeNode* root) {
//         vector<int> temp = {};
//         function<void(TreeNode*, int)> dfs = [&](TreeNode* node, int index) {
//             while (index < temp.size()) {
//                 temp.push_back(NULL);
//             }
//             temp[index] = node->val;
//             if (temp[index] == NULL) {
//                 return;
//             }
//             dfs(node->left, index * 2);
//             dfs(node->left, index * 2 + 1);
//         };
//         dfs(root, 0);

//         vector<string> strTemp(temp.size());
//         transform(temp.begin(), temp.end(), strTemp.begin(), [](int tempVal) {
//             return tempVal != NULL ? to_string(tempVal) : "NULL";
//         });
//         string answer = accumulate(next(strTemp.begin()), strTemp.end(), "", "-");
//         return answer;
//     }

//     // Decodes your encoded data to tree.
//     TreeNode* deserialize(string data) {

//         return nullptr;
//     }
// };