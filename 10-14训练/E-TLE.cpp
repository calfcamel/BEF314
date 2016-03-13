const int kMaxN = 1000000;
char command[kMaxN];
long long arr[kMaxN];
int main() {
  int num_case = 0;
  scanf("%d", &num_case);
  for (int icase = 0; icase < num_case; ++icase) {
    int n;
    long long min_value, max_value;
    scanf("%d%lld%lld", &n, &min_value, &max_value);
    for (int i = 0; i < n; ++i) {
      scanf(" %c%lld", command + i, arr + i);
      if (command[i] == '*' || command[i] == '@') {
        assert(arr[i] <= 100000); // 10^5
      }
    }
    int num_query;
    scanf("%d", &num_query);
    assert(num_query <= 1000000);
    long long ans = 0;
    for (int iquery = 0; iquery < num_query; ++iquery) {
      long long start_value;
      scanf("%lld", &start_value);
      long long sum = start_value;
      for (int i = 0; i < n; ++i) {
        switch(command[i]) {
          case '+':
            sum += arr[i];
            break;
          case '-':
            sum -= arr[i];
            break;
          case '@':
            sum += start_value * arr[i];
            break;
          default:
            sum *= arr[i];
        }
        sum = min(sum, max_value);
        sum = max(sum, min_value);
      }
      ans += sum;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
