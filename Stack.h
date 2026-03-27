class Stack {
  int top_;
  int capacity_;
  int *stack_;

public:
  Stack() = delete;
  explicit Stack(int size);
  Stack(const Stack &stack);
  Stack(Stack &&stack) noexcept;

  Stack &operator=(const Stack &stack);
  Stack &operator=(Stack &&stack) noexcept;

  ~Stack();

  void push(int value);
  void pop();
  int peek() const;
  bool empty() const noexcept;
  bool isFull() const noexcept;
  int capacity() const noexcept;

  friend void printStack(const Stack &stack);
};
