import logo from './logo.svg';
import './App.css';

import { Outlet, redirect, useNavigate } from 'react-router-dom';
import NavigationBar from './components/NavigationBar';
import { useEffect } from 'react';

function App() {
	return (
		<div className="App">
			<NavigationBar />
			<Outlet />
		</div>
	);
}

export default App;
