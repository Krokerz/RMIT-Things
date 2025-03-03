interface TVShow {
  title: string;
  actors: string[] /* Because we have a list, we use an array */;
  year: number;
}

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
 * React components are just functions, we can define them as such.
 * And we can use them in other components, a bit like how you can
 * use functions in other functions.
 */
export function Shows() {
  return (
    <ul>
      {tvShows.map((show) => (
        <li key={show.title}>
          <h2>{show.title}</h2>
          <p>Actors: {show.actors.join(", ")}</p>
          <p>Year: {show.year}</p>
        </li>
      ))}
    </ul>
  );
}

/**
 * Lets make another component, a search bar.
 * This component will be used to search for TV Shows.
 *
 * We won't make it work yet, but let's just play with multiple
 * components.
 */
export function Search() {
  return (
    <div>
      <input type="text" placeholder="Search..." />
    </div>
  );
}

/**
 * We can use these components in our main component.
 * This is a good way to split up our code into smaller, more manageable parts.
 *
 * In this case we want to show a search bar and a list of TV Shows.
 *
 * Try duplicating the Shows component and see what happens. Will it display more than once?
 */
export default function Home() {
  return (
    <div>
      <Search />
      <Shows />
    </div>
  );
}
