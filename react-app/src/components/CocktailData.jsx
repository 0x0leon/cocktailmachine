import React, { Component } from 'react'
import { ListGroup, Card, CardGroup, Container, Col } from 'react-bootstrap';

export default class CocktailData extends Component {
	constructor(props) {
		super(props);

		this.state = {
			items: [],
			DataisLoaded: false
		};
	}


	componentDidMount() {
		
		fetch("http://127.0.0.1:3000/machine/cocktails")
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
			return <div><h1> </h1> </div>;
		return (
			<Container>
				<div className="row">
					{
						items.map((item) => (
							<Col key={item.name} xs="3">
								<Card>
									<Card.Header>{item.name}</Card.Header>
									<Card.Body>
										<Card.Text>promille_ {item.pGehalt}</Card.Text>
									</Card.Body>
								</Card>
							</Col>
						))
					}

				</div>
			</Container>

		)
	}
}
