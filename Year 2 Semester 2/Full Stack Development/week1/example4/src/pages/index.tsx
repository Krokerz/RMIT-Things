/* This is the main component of our page */
export default function Home() {
  /* This function will be called when the button is clicked */
  const handleClick = () => {
    /* Display an alert with a message */
    alert("Button was clicked!");
  };

  /* The return statement defines what will be rendered on the screen */
  return (
    <div>
      {/* This is a button element. When it is clicked, the handleClick function will be called */}
      <button onClick={handleClick}>Click Me</button>
    </div>
  );
}
