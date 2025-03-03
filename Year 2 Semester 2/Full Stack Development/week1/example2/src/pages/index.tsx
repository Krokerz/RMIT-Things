/**
 * Lets define what the structure of a TV Show is.
 * A TV Show has a title, a list of actors and a year.
 */
interface TVShow {
  title: string;
  actors: string[] /* Because we have a list, we use an array */;
  year: number;
}

/**
 * Let's define our list of TV Shows.
 * We can use the interface we defined above to make sure we have the correct structure.
 */
const tvShows: TVShow[] = [
  {
    title: "Breaking Bad",
    actors: ["Bryan Cranston", "Aaron Paul"],
    year: 2008,
  },
  {
    title: "Game of Thrones",
    actors: ["Emilia Clarke", "Kit Harington"],
    year: 2011,
  },
  {
    title: "Stranger Things",
    actors: ["Millie Bobby Brown", "Finn Wolfhard"],
    year: 2016,
  },
  {
    title: "The Mandalorian",
    actors: ["Pedro Pascal", "Gina Carano"],
    year: 2019,
  },
  {
    title: "The Witcher",
    actors: ["Henry Cavill", "Anya Chalotra"],
    year: 2019,
  },
];

/**
 * We can define a function to format the title and year of a TV Show.
 * Notice how we can make sure that we pass in a TV Show object into this function,
 * by typing the parameter as TVShow.
 *
 * We can also type the return value of the function, in this case a string.
 *
 * If we were to pass in a string or a number into this function, TypeScript would throw an error.
 * If we were to rteturn a number or an object, TypeScript would also throw an error.
 *
 * Why? Because we defined the parameter and return value of the function to be of type TVShow and string.
 *
 * Anything else would be invalid. Try it yourself, try changing this function to return a number or an object.
 */
function formatTitleAndYear(show: TVShow): string {
  return `${show.title} (${show.year})`;
}

export default function Home() {
  return (
    <div>
      <h1>Example TV Shows</h1>
      <ul>
        {/* The first argument to map is the element itself, the second is the index */}
        {tvShows.map((show, index) => (
          <li key={index}>
            {/**
             * What is this key thing?
             *
             * React needs a way to identify each element in a list, so it can keep track
             * of which elements have changed, been added or removed. Keys have to be unique
             * and stable, meaning they should not change between renders.
             *
             * In this case, we are using the index of the element in the array as the key.
             * This is not ideal, because if the array changes, the index of each element will change,
             * however, it is fine for this example as we have a static array which will not change.
             *
             * We can use the function we defined above to format the title and year */}
            <strong>{formatTitleAndYear(show)}</strong>
            <ul>
              {/* Lets list the actors of the TV Show */}
              {show.actors.map((actor, actorIndex) => (
                <li key={actorIndex}>{actor}</li>
              ))}
            </ul>
          </li>
        ))}
      </ul>
    </div>
  );
}
