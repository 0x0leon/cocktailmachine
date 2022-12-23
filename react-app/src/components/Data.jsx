import React, { Component } from 'react'
import { ListGroup, Card, CardGroup, Container } from 'react-bootstrap';

export default class Data extends Component {
	constructor(props) {
		super(props);

		this.state = {
			items: [],
			DataisLoaded: false
		};
	}


	componentDidMount() {
		fetch("http://127.0.0.1:3000/machine/dashboard")
			.then((res) => res.json())
			.then((json) => {
				this.setState({
					items: json,
					DataisLoaded: true
				});
			})
	}
	render() {
		const { DataisLoaded, items } = this.state;
		if (!DataisLoaded)
			return <div><h1> Please wait some time.... </h1> </div>;
		return (
			<Container>
				<h1>Data</h1>
				<CardGroup>
					{
						items.map((item) => (
							<Card style={{ width: '18rem' }}>
								<Card.Img variant="top" alt="card image" src="/voddilemon.png" />
								<Card.Body>
									<Card.Title>cocktail: {item.name}</Card.Title>
									<Card.Text>
										Promillegehalt: {item.pGehalt}
									</Card.Text>
								</Card.Body>
								<ListGroup className="list-group-flush">
									<ListGroup.Item>Cras justo odio</ListGroup.Item>
									<ListGroup.Item>Dapibus ac facilisis in</ListGroup.Item>
									<ListGroup.Item>Vestibulum at eros</ListGroup.Item>
								</ListGroup>
								<Card.Body>
									<Card.Link href="#">Card Link</Card.Link>
									<Card.Link href="#">Another Link</Card.Link>
								</Card.Body>
							</Card>
						))
					}



				</CardGroup>

			</Container>

		)
	}
}
