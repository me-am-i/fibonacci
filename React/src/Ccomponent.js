import React from 'react';
import Button from "./Button";

class NetComponent extends React.Component {

    constructor(props){
        super(props);
        this.state = { error: null,
            isLoaded: false,
            value: 0
        }
    }

    componentDidMount() {
        const apiUrl = 'http://127.0.0.1:3001';
        fetch(apiUrl)
            .then((response) => response.json())
            .then((response) => {
                console.log(response.value);
                this.setState({value: response.value});
                this.setState({isLoaded: true});
            })
            .then((error) => {
                this.setState({false: true});
                this.setState({error});
            })

    }


    getNext = (ev) =>{
        ev.preventDefault();
        const apiUrl = 'http://127.0.0.1:3001';
        fetch(apiUrl)
            .then((response) => response.json())
            .then((response) => {
                console.log(response.value);
                this.setState({value: response.value});
                this.setState({isLoaded: true});
            })
            .then((error) => {
                this.setState({false: true});
                this.setState({error});
            })
    }


    render() {
         const { error, isLoaded, value } = this.state;
         if (error) {
             return (<p> Error {error.message}</p>)
         } else if (!isLoaded) {
             return <p>Loading...</p>
         }
        return (<div>
            <h1>{value}</h1>
            <Button getNext={this.getNext} />
            </div>);
    }
}
export default NetComponent;