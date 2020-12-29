import './App.css';
import NetComponent from './Ccomponent';


function App() {
  return (
    <div className="App">
      <header className="App-header">

        <p>
          Fibonacci <br/>
          Числа Фибоначчи — элементы числовой последовательности.<br/>
          0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711...<br/>
          Следующий элемент последовательности Фибоначчи равен:

        </p>
        <NetComponent value="0"/>
        Нажмите на кнопку<br/>

        <button onClick="#"> Reset </button>

      </header>


    </div>
  );
}

export default App;
