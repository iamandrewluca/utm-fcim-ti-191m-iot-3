import React from 'react';
import 'bootstrap/dist/css/bootstrap.min.css'
import { Header } from './Header'

const App: React.FC = () => {
  const [data, setData] = React.useState<any[] | undefined>()
  const [isFetching, setIsFetching] = React.useState(true)

  React.useEffect(function () {
    fetch('/all')
      .then(res => res.json())
      .then(data => new Promise(resolve => setTimeout(resolve, 500, data)))
      .then((data: any) => {
        setData(data)
        setIsFetching(false)
      })
  }, [])

  return (
    <React.Fragment>
      <Header />
      <div className="my-3 container">
        <ul className="list-group">
          {isFetching && (
            <li className="list-group-item d-flex align-items-center">
              Loading...
            </li>
          )}
          {data && data.map(d => (
            <li key={d.id} className="list-group-item d-flex align-items-center">
              {new Date(d.createdAt).toUTCString()}
              <span className="ml-2 badge badge-primary badge-pill">id: {d.id}</span>
              <span className={`ml-auto badge ${d.direction === 'OUT' ? 'badge-warning' : 'badge-success'} badge-pill`}>{d.direction}</span>
            </li>
          ))}
          {data && data.length === 0 && (
            <li className="list-group-item d-flex align-items-center">
              No items
            </li>
          )}
        </ul>
      </div>
    </React.Fragment>
  );
}

export default App;
