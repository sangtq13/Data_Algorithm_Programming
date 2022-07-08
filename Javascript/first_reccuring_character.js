// Time complexity: O(n)
// Space complexity: O(n)
var first_recurring_character = (s) => {
  var d = new Set()
  for (i in s) {
    if (d.has(s[i])) {
      return s[i];
    }
    else {
      d.add(s[i]);
    }
  }

  return 'not-found';
}
