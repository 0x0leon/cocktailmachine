import logo from './logo.svg';
import './App.css';
import { Navbar } from 'react-bootstrap';
import { NavbarMenu } from './components/Navbar';
import Data from './components/Data';
import { Outlet } from 'react-router-dom';

function App() {
	return (
		<div className="App">
			<h1>Startseite</h1>
			<Outlet/>
		</div>
	);
}

export default App;
