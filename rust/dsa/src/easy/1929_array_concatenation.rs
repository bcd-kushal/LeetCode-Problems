impl Solution {
    pub fn get_concatenation(nums: Vec<i32>) -> Vec<i32> {
        let original_arr_length: usize = nums.len();
        let new_arr_length: usize = 2 * original_arr_length;

        let mut result: Vec<i32> = vec![0; new_arr_length];

        for (index, num) in nums.iter().enumerate() {
            result[index] = nums[index];
            result[index+original_arr_length] = nums[index];
        }

        result
    }
}