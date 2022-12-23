import logo from './logo.svg';
import './App.css';
import { Container, Navbar } from 'react-bootstrap';
import { NavbarMenu } from './components/Navbar';
import Data from './components/CocktailData';
import { Outlet } from 'react-router-dom';
import NavigationBar from './components/NavigationBar';

function App() {
	return (
		<div className="App">
			<NavigationBar />
			<Outlet />
		</div>
	);
}

export default App;
