import { useState } from "react";

export default function Home() {
  /**
   * This is a state hook, we can use it to keep track of the count
   *
   * count is the current value of the state
   * setCount is a function that we can use to update the state
   *
   * useState is a generic function, we can pass in the type of the state
   * in this case, we are using a number so we can tell React that the state
   * will always be a number
   *
   * This way if we do something silly like setCount("hello"), TypeScript will
   * throw an error and tell us we are wrong!
   *
   * */
  const [count, setCount] = useState<number>(0);

  return (
    <div>
      {/* React will automatically re-render the component when the state changes */}
      <p>Counter: {count}</p>
      <button onClick={() => setCount((count) => count + 1)}>Increment</button>
    </div>
  );
}
